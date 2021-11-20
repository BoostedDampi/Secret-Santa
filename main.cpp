#include <iostream>     // std::cout
#include <algorithm>    // std::shuffle
#include <vector>       // std::vector
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock
#include <string>
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;



std::vector<std::string> shuffle (std::vector<std::string> names) {



  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine e(seed);

  std::vector<std::string> old = names;

  bool funza = false;
  while(!funza) {

    funza = true;
    for (unsigned int i = 0;i < names.size(); i++) {

      if (names[i] == old[i]) {
        funza = false;
        std::cout << "Redo \n";
        std::shuffle(names.begin(), names.end(), e);
        break;
    }
    }




  }

  return names;
}

 void make_files (std::vector<std::string> names, std::vector<std::string> snames) {

  fs::create_directories("./output");
  for (unsigned int i = 0; i < names.size(); i++) {

    std::string file_name = "output/"+names[i];
    std::ofstream file(file_name);

    file << snames[i];

    file.close();

  }
}


int main ()
{

    std::cout << "Benvenuti nel Secret Santinator 1.2 C++ Edition. \n" <<
    "Scrivi i nomi dei partecipanti e dopo l'ultimo nome scrivi 'exit'.\n";

    std::vector<std::string> names{};

    std::string temp;
    while (42==42) {

      std::cout << ":>>";
      std::cin >> temp;

      if(temp == "exit") {break;}
      names.push_back(temp);
    }

    std::vector<std::string> ah = shuffle(names);

    std::cout << "not shuffled elements:";
    for (std::string& x: names) std::cout << ' ' << x;
    std::cout << '\n';
    std::cout << "abc shuffled elements:";
    for (std::string& x: ah) std::cout << ' ' << x;
    std::cout << '\n';

    make_files(names, ah);


    return 0;
}
