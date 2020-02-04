#!/usr/bin/env python3
"""Module documentation goes here
"""

import subprocess
import sys

class QuickTest:
    """Class documentation goes here
    """
    def __init__(self):
        self._app = "./binary_converter"
        self._input = ["0 0", "33 0", "8 -31", "4 5", "8 37"]
        self._output = [(1, ), (1, ), (2, ), (0, "0101"), (0, "00100101")]


    def test(self, test_no):
        """Method documentation goes here
        """
        returncode, out = self.run(test_no)
        out = str.strip(out) if out else None

        if self._output[test_no][0] == returncode:
            print("RETURN CODE CORRECT")
        else:
            print(
                "ERROR: EXPECTED return {}, ACTUAL return {}.".format(
                    self._output[test_no][0], returncode), file=sys.stderr)

        if not out and len(self._output[test_no]) > 1:
            print("ERROR: No output from student app.", file=sys.stderr)
            return
            sys.exit(1)

        if len(self._output[test_no]) == 1 or self._output[test_no] == 2:
            # bad input size or negative decimal value
            return
            sys.exit(0)

        if self._output[test_no][1] == out:
            print("OUTPUT CORRECT")
        else:
            print("ERROR: EXPECTED {}, ACTUAL {}".format(
                self._output[test_no][1], out, file=sys.stderr))


    def run(self, test_no):
        """Method documentation goes here.
        """
        with subprocess.Popen(self._app, stderr=subprocess.PIPE,
                stdin=subprocess.PIPE, stdout=subprocess.PIPE) as proc:
          out, err = proc.communicate(
              input=self._input[test_no].encode("utf-8"))
          
          try:
            return proc.returncode, out.decode("utf-8") if out else None
          except UnicodeDecodeError as e:
            return proc.returncode, "Serious execution badness:" + format(e)


if __name__ == "__main__":
    test = QuickTest()
    test.test(int(sys.argv[1]))
