#ifndef BIT_MANIPULATION_H_
#define BIT_MANIPULATION_H_

/****************************************************************************/
/*                                                                          */
/*                       BIT Manipulation for GPIO                          */
/*                                                                          */
/****************************************************************************/

#define GPIO_SET(reg,bit)    ( *(reg) |=  (1 << bit) )
#define GPIO_CLEAR(reg,bit)  ( *(reg) &= ~(1 << bit) )
#define GPIO_TOGGLE(reg,bit) ( *(reg) ^=  (1 << bit) )
#define GPIO_IS_SET(reg,bit) ((*(reg) & (1 << bit)) >> bit)

/****************************************************************************/
/*                                                                          */
/*                        BIT Manipulation for registers                    */
/*                                                                          */
/****************************************************************************/

#define BIT_SET(reg,bit)    ( (reg) |=  (1 << bit) )
#define BIT_CLEAR(reg,bit)  ( (reg) &= ~(1 << bit) )
#define BIT_TOGGLE(reg,bit) ( (reg) ^=  (1 << bit) )
#define BIT_IS_SET(reg,bit) (((reg) & (1 << bit)) >> bit)

/****************************************************************************/
/*                                                                          */
/*                        Register Manipulation                             */
/*                                                                          */
/****************************************************************************/

#define REG_SET(reg,val) ( (reg) |= (val)   )
#define REG_CLEAR(reg)   ( (reg) |= (0x00)  )


#endif 