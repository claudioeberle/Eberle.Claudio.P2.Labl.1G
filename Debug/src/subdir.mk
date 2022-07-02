################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/2do_Parcial_LaboratorioI_Eberle.c \
../src/LinkedList.c \
../src/controller.c \
../src/ioput.c \
../src/movie.c \
../src/parser.c 

C_DEPS += \
./src/2do_Parcial_LaboratorioI_Eberle.d \
./src/LinkedList.d \
./src/controller.d \
./src/ioput.d \
./src/movie.d \
./src/parser.d 

OBJS += \
./src/2do_Parcial_LaboratorioI_Eberle.o \
./src/LinkedList.o \
./src/controller.o \
./src/ioput.o \
./src/movie.o \
./src/parser.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/2do_Parcial_LaboratorioI_Eberle.d ./src/2do_Parcial_LaboratorioI_Eberle.o ./src/LinkedList.d ./src/LinkedList.o ./src/controller.d ./src/controller.o ./src/ioput.d ./src/ioput.o ./src/movie.d ./src/movie.o ./src/parser.d ./src/parser.o

.PHONY: clean-src

