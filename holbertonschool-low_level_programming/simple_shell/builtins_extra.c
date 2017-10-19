#include "shell_head.h"
#include "shell_builtins.h"

/*
*still under consturtion, once instituted the help built in
*will help direct the user if the need be
*/
int builtin_help(__attribute__((unused)) int ac, __attribute__((unused)) char **cmd, __attribute__((unused)) char **env)
{
        print_string("Google it...\n");
        
        return (0);
}
