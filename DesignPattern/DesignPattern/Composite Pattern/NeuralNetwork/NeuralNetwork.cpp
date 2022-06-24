#include "NeuralNetwork.h"

namespace NeuralNetwork
{
	template<typename Self>
	template<typename T>
	inline void SomeNeurons<Self>::connect_t(T& other)
	{
		for (Neuron& from : *static_cast<Self*>(this))
		{
			for (Neuron& to : other)
			{
				from.out.push_back(&to);
				to.in.push_back(&from);
			}
		}
	}

	Neuron::Neuron()
	{
		static int id = 1;
		this->id = id++;
	}

	Neuron* Neuron::begin()
	{
		return this;
	}

	Neuron* Neuron::end()
	{
		return this + 1;
	}

	NeuronLayer::NeuronLayer(int count)
	{
		while (count-- > 0)
		{
			emplace_back(Neuron{});
		}
	}

	void NeuralNetworkTest::Run()
	{
		Neuron neuron0, neuron1;
		NeuronLayer layer0(4), layer1(4);

		neuron0.connect_t(neuron1);
		neuron0.connect_t(layer0);
		layer0.connect_t(neuron0);
		layer0.connect_t(layer1);
	}
}