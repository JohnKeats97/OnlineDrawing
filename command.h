#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <vector>

// Базовый класс
class Command
{
  public:
    virtual ~Command() {}
    virtual void execute( std::vector<points>& Vector_point ) = 0;
  protected:
    Command( std::vector<points>& p ): change_point( p) {}
    std::vector<points>& change_point;
};

class Command_GetChange: public Command
{
  public:
    Command_GetChange( std::vector<points>& change_point ) : Command( change_point ) {}
    void execute ( std::vector<points>& Vector_point ) {
      Vector_point = change_point;
    }
};


#endif // COMMAND_H

