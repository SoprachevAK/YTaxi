
#include <iostream>

void graph();
void collectInfo();

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cerr << "Incorrect parameters count\n";
    return 1;
  }
  try
  {
    switch (std::stoi(argv[1]))
    {
      case 1:
        collectInfo();
        break;
      case 2:
        graph();
        break;
      default:
        std::cerr << "Incorrect task num\n";
        return 1;

    }
  }
  catch (std::exception &exception)
  {
    std::cerr << exception.what() << '\n';
    return 1;
  }
  return 0;
}
