// clEnvironment.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <CL/opencl.hpp>

namespace clEnvironment {
	class Environment {
	protected:
		virtual void updateStates(const cl::Buffer& actions) = 0;

	public:
		cl::Buffer states;
		cl::Buffer reward;

		Environment(const cl::Context context, const cl::Buffer& starting_states) : states(starting_states) {};
	};
}