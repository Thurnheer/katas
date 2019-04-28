#include "single_number.hpp"
#include <benchmark/benchmark.h>
#include <iostream>

class ArrayProviderFixture : public ::benchmark::Fixture
{
public:
  void SetUp(const ::benchmark::State& st)
  {
    unsigned int vec_size = (st.range(0) * 3) + 1;
    input_data            = std::vector<int>(vec_size);

    for(auto i = 0; i < st.range(0); i++)
    {
      input_data[i * 3]     = i;
      input_data[i * 3 + 1] = i;
      input_data[i * 3 + 2] = i;
    }

    input_data[input_data.size() - 1] = -2;
  }

  void TearDown(const ::benchmark::State&)
  {
    input_data.clear();
  }

  std::vector<int> input_data;
};

BENCHMARK_DEFINE_F(ArrayProviderFixture, find_single_number)(benchmark::State& state)
{
  for(auto _ : state)
    benchmark::DoNotOptimize(kata::find_single_number(input_data));

  state.SetComplexityN(state.range(0)*3);
}

BENCHMARK_REGISTER_F(ArrayProviderFixture, find_single_number)
    ->Range(8, 8 << 10)
    ->Complexity();

BENCHMARK_MAIN();
