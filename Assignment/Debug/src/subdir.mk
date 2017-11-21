################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Assignment.cpp 

OBJS += \
./src/Assignment.o 

CPP_DEPS += \
./src/Assignment.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DIL_STD -I/opt/ibm/ILOG/CPLEX_Studio1271/concert/include -I/opt/ibm/ILOG/CPLEX_Studio1271/cplex/include -O0 -g3 -Wall -c -fmessage-length=0 -m64 -O -fPIC -fexceptions -DIL_STD -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


