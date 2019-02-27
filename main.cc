/**
 * Copyright 2019 Ashar <ashar786khan@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <benchmark.hpp>
#include <blas_matrix.hpp>
#include <chrono>
#include <thread>
void some_func(void) {
  std::this_thread::sleep_for(std::chrono::microseconds(1500000));
}

int main() {
  using boost::test::benchmark;
  using mat = boost::test::blas_matrix<int>;
  mat a = {{1, 5, 6, 8}, 
               {7, 8, 6, 9}, 
               {8, 3, 4, 5}, 
               {9, 9, 5, 2}};

  mat b = {{1, 5, 6, 8}, 
               {7, 8, 6, 9}, 
               {8, 3, 4, 5}, 
               {9, 9, 5, 2}};
  
  mat c = a + b - b;
  mat d = a - b + b * c;
  // std::cout<<5 + 5 << "\n";
  c.view();
  d.view();

  return 0;
}
