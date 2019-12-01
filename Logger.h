
#define DUMP(logfile, name, value) if (debug) fprintf(logfile, "%s = %.3f\n", name, value);
#define DUMP_PAIR_FLOAT_STRING(logfile, name_first, value_first, name_second, value_second)\
 if (debug) fprintf(logfile, "%s = %.3f\t\t%s = %d\n", name_first, value_first, name_second, value_second);
#define DUMP_INT(logfile, name, value) if (debug) fprintf(logfile, "%s = %d\n", name, value);
#define PRINT(logfile, varname) if (debug) fprintf(logfile, "%s\n", varname);

extern FILE* logfile;
extern bool debug;


