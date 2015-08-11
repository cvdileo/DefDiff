#ifndef DEFDIFFAPP_H
#define DEFDIFFAPP_H

#include "MooseApp.h"

class DefdiffApp;

template<>
InputParameters validParams<DefdiffApp>();

class DefdiffApp : public MooseApp
{
public:
  DefdiffApp(InputParameters parameters);
  virtual ~DefdiffApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* DEFDIFFAPP_H */
