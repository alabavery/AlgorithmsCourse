################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/UnionFind/IUnionFind.cpp \
../src/UnionFind/QuickFind.cpp \
../src/UnionFind/QuickUnion.cpp \
../src/UnionFind/StdInputReading.cpp 

OBJS += \
./src/UnionFind/IUnionFind.o \
./src/UnionFind/QuickFind.o \
./src/UnionFind/QuickUnion.o \
./src/UnionFind/StdInputReading.o 

CPP_DEPS += \
./src/UnionFind/IUnionFind.d \
./src/UnionFind/QuickFind.d \
./src/UnionFind/QuickUnion.d \
./src/UnionFind/StdInputReading.d 


# Each subdirectory must supply rules for building sources it contributes
src/UnionFind/%.o: ../src/UnionFind/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


