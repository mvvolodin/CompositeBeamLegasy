
#define DUMP(logfile, name, value) if (debug) fprintf(logfile, "%s = %.3f\n", name, value);
#define DUMP_INT(logfile, name, value) if (debug) fprintf(logfile, "%s = %d\n", name, value);
#define PRINT(logfile, varname) if (debug) fprintf(logfile, "%s\n", varname);

extern FILE* logfile;
extern bool debug;


