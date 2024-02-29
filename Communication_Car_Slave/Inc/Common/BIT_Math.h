#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(REG,BIT_NUM) (REG|=1<<BIT_NUM)
#define CLR_BIT(REG,BIT_NUM) REG&=~(1<<BIT_NUM)
#define TOGGLE_BIT(REG,BIT_NUM) REG^=(1<<BIT_NUM)
#define GET_BIT(REG,BIT_NUM) (1&(REG>>BIT_NUM))

#define READ_REG(REG)			((REG))
#define WRITE_REG(REG, VAL)		((REG) = (VAL))
#define MODIFY_REG(REG, MASK, VAL)	WRITE_REG((REG), (((READ_REG(REG)) & (~(MASK))) | (VAL)))

#endif
