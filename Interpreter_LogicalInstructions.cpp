/*
 *  Interpreter_LogicalInstructions.cpp
 *  mindstormssimulation
 *
 *  Created by Torsten Kammer on 26.04.10
 *  Copyright 2010 RWTH Aachen University All rights reserved.
 *
 */

#include "Interpreter.h"

#include <iostream>

#include "RXEFile.h"
#include "VMMemory.h"

void Interpreter::op_and(unsigned flags, const uint16_t *params)
{
	// Params:
	// 0: Destination, memory location
	// 1: A, memory location
	// 2: B, memory location

	int a = memory->getScalarValue(params[1]);
	int b = memory->getScalarValue(params[2]);

	memory->setScalarValue(params[0], a & b);
}

void Interpreter::op_or(unsigned flags, const uint16_t *params)
{
	// Params:
	// 0: Destination, memory location
	// 1: A, memory location
	// 2: B, memory location

	int a = memory->getScalarValue(params[1]);
	int b = memory->getScalarValue(params[2]);

	memory->setScalarValue(params[0], a | b);
}

void Interpreter::op_xor(unsigned flags, const uint16_t *params)
{
	// Params:
	// 0: Destination, memory location
	// 1: A, memory location
	// 2: B, memory location

	int a = memory->getScalarValue(params[1]);
	int b = memory->getScalarValue(params[2]);

	memory->setScalarValue(params[0], a ^ b);
}

void Interpreter::op_not(unsigned flags, const uint16_t *params)
{
	// Params:
	// 0: Destination, memory location
	// 1: A, memory location
	
	int a = memory->getScalarValue(params[1]);
	
	// Notice: This is logical, not bitwise, per Lego documentation
	memory->setScalarValue(params[0], !a);
}
