#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace NeuralNetwork
{
	template<typename Self>
	struct SomeNeurons
	{
		template <typename T> void connect_t(T& other);
	};

	struct Neuron : SomeNeurons<Neuron>
	{
		std::vector<Neuron*> in, out;
		unsigned int id;

		Neuron();

		Neuron* begin();
		Neuron* end();
	};

	struct NeuronLayer : std::vector<Neuron>, SomeNeurons<NeuronLayer>
	{
		NeuronLayer(int count);
	};

	struct NeuralNetworkTest
	{
		static void Run();
	};
};