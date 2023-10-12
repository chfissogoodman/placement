#include "include/parser.h"
#include "include/place.h"
#include "include/exporter.h"

int main() {
Parser parser;
if(parser.parseFile("input.txt"))
{
  const Database &database=parser.getDatabase();

}
}
