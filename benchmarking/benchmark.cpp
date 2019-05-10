#include <solution.hpp>

#include <benchmark/benchmark.h>
#include <random>


class StockTester : public ::benchmark::Fixture

{

public:

  void SetUp(const ::benchmark::State& st) override

  {

    input = std::vector<double>(st.range(0));

    constexpr int fixed_seed = 3;

    std::mt19937  gen(fixed_seed);

    std::uniform_int_distribution<> dis(1, 100);

    for(auto& val : input)

      val = dis(gen);

  }

 

 void TearDown(const ::benchmark::State&) override

  {

    input.clear();

  }

  std::vector<double> input;

};

 

BENCHMARK_DEFINE_F(StockTester, howFastDoWeCalculateProfit)(benchmark::State& state)

{

  for(auto _ : state)

    benchmark::DoNotOptimize(kata::calculate_max_profit(input));

  state.SetComplexityN(state.range(0));

}

 

constexpr unsigned int minNumberOfElements{1};

constexpr unsigned int maxNumberOfElements{std::numeric_limits<int32_t>::max() / 8};

 

BENCHMARK_REGISTER_F(StockTester, howFastDoWeCalculateProfit)

->RangeMultiplier(2)

  ->Range(minNumberOfElements, maxNumberOfElements)

  ->Complexity();

 
BENCHMARK_MAIN();
