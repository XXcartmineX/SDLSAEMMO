################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Source\ files/Server.cpp \
../Source\ files/main.cpp 

OBJS += \
./Source\ files/Server.o \
./Source\ files/main.o 

CPP_DEPS += \
./Source\ files/Server.d \
./Source\ files/main.d 


# Each subdirectory must supply rules for building sources it contributes
Source\ files/Server.o: ../Source\ files/Server.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -pthread -std=c++11 -Wl,--no-as-needed -MMD -MP -MF"Source files/Server.d" -MT"Source\ files/Server.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source\ files/main.o: ../Source\ files/main.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -pthread -std=c++11 -Wl,--no-as-needed -MMD -MP -MF"Source files/main.d" -MT"Source\ files/main.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


