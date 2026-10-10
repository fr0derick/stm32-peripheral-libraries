# STM32 Peripheral Libraries

My personal collection of small C libraries for connecting external peripherals to STM32 microcontrollers using the STM32 HAL.
These examples targeted the **Nucleo-L412KB**
This is mainly for my embedded systems module at university

## Peripherals

### 16X2 Display Functions

| Function | Purpose |
| --- | --- |
| `LCD16X2_Init(index)` | Initialize the LCD in 4-bit mode |
| `LCD16X2_Clear(index)` | Clear the display and return the cursor to the beginning |
| `LCD16X2_SetCursor(index, row, col)` | Set the cursor position |
| `LCD16X2_WriteChar(index, ch)` | Write one character |
| `LCD16X2_WriteString(index, str)` | Write a null-terminated string |
| `LCD16X2_WriteInt(index, number)` | Write a signed integer in decimal |
| `LCD16X2_ShiftLeft(index)` | Shift the displayed contents left |
| `LCD16X2_ShiftRight(index)` | Shift the displayed contents right |

The LCD indexes start at 0, and the default config supports one LCD so use LCD16X2_1 which is defined as `0`

## Plans

- I'm planning to add a library for interfacing a **4X4 Keypad**
- And more, possibly.

## Acknowledgements

Learning resource: Khaled Magdy's [STM32 LCD 16×2 tutorial on DeepBlueMbedded](https://deepbluembedded.com/stm32-lcd-16x2-tutorial-library-alphanumeric-lcd-16x2-interfacing/).

