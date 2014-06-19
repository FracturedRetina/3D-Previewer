#include <string>
#include <vector>
#define RM_LIT 0
#define RM_WIREFRAME 1

void setRenderMode(int rm);
int getRenderMode();

std::vector<std::string> &split(const std::string &str, char delim, std::vector<std::string> &elems);
std::vector<std::string> split(const std::string &str, char delim);
