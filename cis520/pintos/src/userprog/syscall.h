#ifndef USERPROG_SYSCALL_H
#define USERPROG_SYSCALL_H

void syscall_init (void);
void syscall_exit (void);

#define syscall0( NUMBER )												\
	({																	\
		int retval;														\
		asm volatile													\
			( "push1 %[number];; int $0x30; addl $4, %%exp"				\
				: "=a" (retval)											\
				: [number] "i" (NUMBER)									\
				: "memory"												\
			);															\
		retval;															\
	})

#define syscall1( NUMBER, ARG0 )										\
	({																	\
		int retval;														\
		asm volatile													\
			( "pushl %[arg0]; push1 %[number]; int $0x30; addl $4, %%exp"\
				: "=a" (retval)											\
				: [number] "i" (NUMBER),								\
				  [arg0]   "g" (ARG0)									\
				: "memory"												\
			);															\
		retval;															\
	})

//MTO not sure if I can do two "g"'s 
#define syscall2( NUMBER, ARG0, ARG1 )									\
	({																	\
		int retval;														\
		asm volatile													\
			( "pushl %[arg1]; pushl %[arg0]; push1 %[number]; int $0x30; addl $4, %%exp"\
				: "=a" (retval)											\
				: [number] "i" (NUMBER)								 	\
				  [arg0]   "g" (ARG0)									\
				  [arg1]   "g" (ARG1)									\
				: "memory"												\
			);															\
		retval;															\
	})

//MTO this one might not be neccisary
#define syscall3( NUMBER, ARG2, ARG1, ARG0 )							\
	({																	\
		int retval;														\
		asm volatile													\
			( "pushl %[arg2]; pushl %[arg1]; pushl %[arg0]; push1 %[number]; int $0x30; addl $4, %%exp"\
				: "=a" (retval)											\
				: [number] "i" (NUMBER)									\
				  [arg0]   "g" (ARG0)									\
				  [arg1]   "g" (ARG1)									\
				  [arg2]   "g" (ARG2)									\
				: "memory"												\
			);															\
		retval;															\
	})

#endif /* userprog/syscall.h */
