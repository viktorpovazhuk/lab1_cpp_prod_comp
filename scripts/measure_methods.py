import sys
from subprocess import Popen, PIPE


def main():
    if len(sys.argv) != 4:
        print('Incorrect number of script arguments')
        return

    repetitions = int(sys.argv[1])
    input_file = sys.argv[2]
    output_file = sys.argv[3]

    methods = 5
    eps = 1 * 10 ** (-8)

    result = {"stringstream": 0, "stod": 0, "sscanf": 0, "boost": 0, "Qt": 0}

    for m in range(methods):
        prev_val, cur_val = (0, 0), (0, 0)
        smallest_time = float('inf')

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

            if smallest_time > time:
                smallest_time = time

            prev_val = cur_val
            with open(output_file, "r") as f:
                cur_val = float(f.readline()), float(f.readline())
            if i == 0:
                continue
            if (prev_val[0] - cur_val[0] > eps) or (prev_val[1] - cur_val[1] > eps):
                print(f"Different results for method {m + 1}")

        result[list(result.keys())[m]] = smallest_time
    print_res(result)


def print_res(res):
    print("\nString to double convertion, us:\n")
    for i in sorted(res.items(), key=lambda x: x[1]):
        print(f"Using {i[0]}: {i[1]}")
    print("\nAll results are the same.\n")


main()
