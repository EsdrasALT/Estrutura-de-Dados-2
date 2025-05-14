################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/LLRB.c \
../src/mainLLRB.c 

C_DEPS += \
./src/LLRB.d \
./src/mainLLRB.d 

OBJS += \
./src/LLRB.o \
./src/mainLLRB.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/LLRB.d ./src/LLRB.o ./src/mainLLRB.d ./src/mainLLRB.o

.PHONY: clean-src

