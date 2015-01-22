#include "DefdiffApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

template<>
InputParameters validParams<DefdiffApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  return params;
}

DefdiffApp::DefdiffApp(const std::string & name, InputParameters parameters) :
    MooseApp(name, parameters)
{
  srand(processor_id());

  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  DefdiffApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  DefdiffApp::associateSyntax(_syntax, _action_factory);
}

DefdiffApp::~DefdiffApp()
{
}

void
DefdiffApp::registerApps()
{
  registerApp(DefdiffApp);
}

void
DefdiffApp::registerObjects(Factory & factory)
{
}

void
DefdiffApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
