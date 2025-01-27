// clEnvironment.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <CL/opencl.hpp>

namespace clEnvironment {
	class Environment {
	public:
		cl::Buffer states;
		cl::Buffer reward;

		Environment(const cl::Context context, const cl::Buffer& starting_states) : states(starting_states) {};
		virtual void updateStates(const cl::Buffer& actions) = 0;
		virtual const cl::Buffer &getStates() final { return states; }
		virtual const cl::Buffer &getRewards() final { return reward; }
	};
}
