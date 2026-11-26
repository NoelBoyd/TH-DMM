# STM32 & Embedded C Best Practices Guide

This guide compiles essential best practices, tips, and tricks for developing robust firmware for STM32 microcontrollers using Embedded C.

## 1. STM32 Project & Architecture Setup
* **Don't Skip Generations:** If you are a beginner, start with simpler architectures (like the STM32F1 or F4 series) before moving to advanced cores (like STM32H7) to avoid the overwhelming complexity of caches and memory protection units.
* **Standardize Your Framework:** Use **STM32CubeMX** to initialize peripherals and generate code. Stick to a consistent abstraction layer—typically the **HAL (Hardware Abstraction Layer)** for portability, or **LL (Low-Layer)** for performance. 
* **Never Mix Paradigms:** Do not mix direct register modifications, SPL (Standard Peripheral Library), and HAL within the same source file. This breaks portability and causes clock synchronization bugs.
* **Understand the 4 Pillars:** Over 90% of STM32 bugs stem from misunderstanding:
  1. **Clock Tree:** Always ensure peripheral clocks are enabled before use.
  2. **NVIC (Nested Vectored Interrupt Controller):** Configure preemption priorities carefully to avoid nested interrupt deadlocks.
  3. **GPIO Multiplexing:** Verify alternate functions are assigned correctly.
  4. **Bus Architectures:** Know your AHB/APB1/APB2 bus limits.

## 2. Embedded C Best Practices
* **Use Fixed-Width Integers:** Never use standard `int`, `short`, or `long`. Always use `<stdint.h>` types like `uint8_t`, `int16_t`, and `uint32_t` to guarantee size across different architectures.
* **The `volatile` Keyword:** Always mark variables modified inside an Interrupt Service Routine (ISR) or mapped to hardware registers as `volatile`. This stops the compiler from optimizing away memory reads/writes.
* **Const Discipline:** Use `const` heavily for read-only look-up tables, configuration structs, and pointer parameters that shouldn't modify the caller's data. This saves precious RAM by placing data in Flash.
* **Avoid Magic Numbers:** Never hardcode values like `delay(1250)`. Use `enum` (preferred for state machines), `const`, or `#define` to give values meaningful names.
* **Avoid Dynamic Memory (`malloc`/`free`):** Avoid heap allocation in embedded systems to prevent memory fragmentation and hard-to-detect memory leaks. Statically allocate memory or use memory pools.
* **Prefer `static inline` over Macros:** Use `static inline` functions for small, repetitive operations rather than `#define` macros to ensure strict type checking and avoid side-effects.

## 3. STM32 Coding Tips & Tricks
* **Keep ISRs Tiny:** Interrupt Service Routines should execute as fast as possible. Simply clear the interrupt flag, set a volatile state flag, or copy minimal data, and defer the heavy processing to your main `while(1)` loop or RTOS task.
* **Check HAL Return Values:** Do not assume functions succeed. Always explicitly check return values to catch silent failures: 
  ```c
  if (HAL_UART_Transmit(&huart2, data, size, HAL_MAX_DELAY) != HAL_OK) { 
      Error_Handler(); 
  }
  ```
* **Leverage DMA (Direct Memory Access):** For ADCs, UARTs, and SPI transfers, use DMA instead of blocking polling modes (`HAL_..._Transmit` vs `HAL_..._Transmit_DMA`). This frees up the CPU to perform other tasks while data transfers in the background.
* **Low-Power Modes:** If running on a battery, utilize STM32's Sleep, Stop, and Standby modes. Use the `__WFI()` (Wait For Interrupt) instruction in your main loop to pause the CPU until the next event occurs.

## 4. Debugging & Workflow
* **Ditch `printf` Debugging:** Master hardware debuggers (ST-Link / J-Link). Rely on breakpoints, the watch window, and the memory viewer in STM32CubeIDE to inspect live variables and memory regions.
* **HardFault Debugging:** If your code crashes, learn to read the Stack Pointer and fault registers (like CFSR). HardFaults usually happen due to null pointer dereferences, stack overflows, or accessing unclocked peripherals.
* **Use Version Control:** Commit your working state in Git before making significant changes to STM32CubeMX `.ioc` files, as regenerating code can occasionally overwrite custom logic if placed outside of the `/* USER CODE BEGIN/END */` blocks.