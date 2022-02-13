import sys
from subprocess import Popen, PIPE


def main():
    if len(sys.argv) != 4:
        print('Incorrect number of script arguments')
        return

    repetitions = int(sys.argv[1])
    input_file = sys.argv[2]
    output_file = sys.argv[3]

    methods = 3
    eps = 1 * 10 ** (-8)

    times = [0 for _ in range(methods)]

    for m in range(methods):
        prev_val, cur_val = (0, 0), (0, 0)
        small_time = float('inf')

        for i in range(repetitions):
            proc = Popen(["./converter", str(m + 1),
                         input_file, output_file], stdout=PIPE, stderr=PIPE)

            (time, error) = proc.communicate()
            exit_code = proc.wait()

            if exit_code != 0:
                print(str(error)[2:-3])
                return

            error = str(error)
            time = int(time)

            if small_time > time:
                small_time = time

            prev_val = cur_val
            with open(output_file, "r") as f:
                cur_val = float(f.readline()), float(f.readline())
            if i == 0:
                continue
            if (prev_val[0] - cur_val[0] > eps) or (prev_val[1] - cur_val[1] > eps):
                print(f"Different results for method {m + 1}")

        times[m] = small_time
    print_res(times)


def print_res(times):
    print(f"String to double convertion, us:\n"
          f"Using stringstream: {times[0]}\n"
          f"Using stod: {times[1]}\n"
          f"Using sscanf: {times[2]}\n\n"
          f"All results are the same.\n")


main()
