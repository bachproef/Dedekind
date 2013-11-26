################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AMFunction.cpp \
../src/Parser.cpp \
../src/SmallBasicSet.cpp \
../src/tests.cpp \
../src/toolbox.cpp 

OBJS += \
./src/AMFunction.o \
./src/Parser.o \
./src/SmallBasicSet.o \
./src/tests.o \
./src/toolbox.o 

CPP_DEPS += \
./src/AMFunction.d \
./src/Parser.d \
./src/SmallBasicSet.d \
./src/tests.d \
./src/toolbox.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


