import os, sys

help = """
    Usage: create.py [options] [arguments]
    """

class makefile:

    CC = "gcc"
    CFLAGS = ""

    dir_path = os.path.dirname(os.path.abspath(__file__))
    file_names = [file_name for file_name in os.listdir(dir_path) if file_name.endswith('.c')]
    SRC = file_names[0]

    file_path = os.path.abspath(__file__)
    parent_dir = os.path.dirname(file_path)
    EXEC = str(parent_dir.split('/')[-1])

    template = f"""# Makefile template for C projects

# Compiler and compiler flags
CC = """ + CC + """
CFLAGS = """ + CFLAGS + """

# Source file and executable name
SRC = """ + SRC + """
EXEC = """ + EXEC + """

# Default rule
all : $(EXEC)

# Rule to build the executable
$(EXEC) : $(SRC)
\t$(CC) $(CFLAGS) -o $@ $<

# Rule to build the executable with debugging information
debug : $(SRC)
\t$(CC) $(CFLAGS) -g -o $(EXEC) $<
\tgdb $(EXEC)
\t$(MAKE) clean

# Rule to clean up generated files
clean :
\trm -vf $(EXEC)
"""

    def __init__(self, CC, CFLAGS, SRC, EXEC):
        self.CC = CC
        self.CFLAGS = CFLAGS
        self.SRC = SRC
        self.EXEC = EXEC

    def create(self):
        with open("makefile", 'w') as f:
            f.write(self.template)

    def lag(self, lags: str):
        self.CFLAGS += lags


class interactive:

    if len(sys.argv) > 1:
        argv = sys.argv[1:]
    else:
        argv = []

    def __init__(self, argv):
        self.argv = argv

    def pap(self):
        # Parameter processing
        if len(self.argv) == 0 or self.argv[0] == '-c' or self.argv[0] == '--create':
            mf = makefile(makefile.CC, makefile.CFLAGS, makefile.SRC, makefile.EXEC)
            mf.create()

        elif self.argv[0] == '-h' or self.argv[0] == '--help':
            print(help)

        elif self.argv[0] == '-v' or self.argv[0] == '--version':
            print("Version 1.0.0")

        elif self.argv[0] == '-d' or self.argv[0] == '--debug':
            mf = makefile(makefile.CC, makefile.CFLAGS, makefile.SRC, makefile.EXEC)
            mf.create()
            os.system("make debug")

        elif self.argv[0] == '-l' or self.argv[0] == '--lag':
            mf = makefile(makefile.CC, makefile.CFLAGS, makefile.SRC, makefile.EXEC)
            mf.lag(self.argv[1])
            mf.create()

def main():
    inter = interactive(interactive.argv)
    inter.pap()


if __name__ == "__main__":
    main()