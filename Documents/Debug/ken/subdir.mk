################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ken/gotoxy.cpp \
../ken/main.cpp 

OBJS += \
./ken/gotoxy.o \
./ken/main.o 

CPP_DEPS += \
./ken/gotoxy.d \
./ken/main.d 


# Each subdirectory must supply rules for building sources it contributes
ken/%.o: ../ken/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -pthread -std=c++11 -Wl,--no-as-needed -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


