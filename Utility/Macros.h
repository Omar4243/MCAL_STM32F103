// Header: Stm32f103c8 Drivers
// File Name: MACROS
// Author: Omar Megahed Ismail
// Date: 2022/03/16
#ifndef MACROS_H_
#define MACROS_H_

#define   SET_BIT(REGISTER,BIT)        ((REGISTER)|=(1u<<(BIT)))
#define   CLEAR_BIT(REGISTER,BIT)      ((REGISTER)&= ~(1u<<(BIT)))
#define   IS_BIT_SET(REGISTER,BIT)     (((REGISTER) & (1u<<(BIT)))>>(BIT))
#define   IS_BIT_CLEAR(REGISTER,BIT)   (!IS_BIT_SET(REGISTER,BIT))
#define   TOGGEL_BIT(REGISTER,BIT)     ((REGISTER)^=(1u<<(BIT)))
#define   CHECK_BIT(Reg,bit)           ((Reg>>bit)&1u)


#endif
