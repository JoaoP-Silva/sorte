import matplotlib.pyplot as plt
import numpy as np



def genGraphics(sets, titles, name):
    x = [1000, 5000, 10000, 50000, 100000, 500000, 1000000]

    colors = ['b', 'g', 'r', 'c', 'm', 'y', 'k', 'w']

    fig, axis  = plt.subplots(1,3)
    for i in range(len(sets)):
        time = sets[i][0]
        keys = sets[i][1]
        regs = sets[i][2]
        
        axis[0].plot(x, time, color = colors[i])
        axis[0].set_xlabel("N")
        axis[0].set_ylabel("Tempo total (segundos)")
        axis[0].set_title("Tempo")

        axis[1].plot(x, keys, color = colors[i])
        axis[1].set_xlabel("N")
        axis[1].set_ylabel("Chaves comparadas")
        axis[1].set_title("Comparações")

        axis[2].plot(x, regs, color = colors[i])
        axis[2].set_xlabel("N")
        axis[2].set_ylabel("Cópias de registro")
        axis[2].set_title("Cópias")

    fig.legend(titles, bbox_to_anchor=(0.3, 1.2))
    plt.tight_layout()
    plt.savefig("graphics/%s.png"%(name), bbox_inches = 'tight')


    





if __name__ == '__main__':
    print("Digite o numero de arquivos de saída gerados")
    n = int(input())
    sortMethods = ["Recursivo padrao", "Mediana", "Seleção",
                    "Iterativo", "Empilha inteligente"]
    
    #Lists to save all results
    rQ1 = np.zeros((3,7))
    rQ2_3 = np.zeros((3,7))
    rQ2_5 = np.zeros((3,7))
    rQ2_7 = np.zeros((3,7))
    rQ3_10 = np.zeros((3,7))
    rQ3_100 = np.zeros((3,7))
    rQ4 = np.zeros((3,7))
    rQ5 = np.zeros((3,7))
    rmerge = np.zeros((3,7))
    rheap = np.zeros((3,7))

    nExp = 7

    for num in range(n):
        f = open("saida%d.txt"%(num))
        l = f.readline()
        count = 0
        for i in range(nExp):
            time = l.split(":")[-1]
            time = float(time.strip()) / n
            rQ1[0][i] += time
            l = f.readline()
            keys = l.split(":")[-1]
            keys = float(keys.strip()) / n
            rQ1[1][i] += keys
            l = f.readline()
            reg = l.split(":")[-1]
            reg = float(reg.strip()) / n
            rQ1[2][i] += reg
            l = f.readline()
        print(l)
        for i in range(nExp):
            time = l.split(":")[-1]
            time = float(time.strip()) / n
            rQ2_3[0][i] += time
            l = f.readline()
            keys = l.split(":")[-1]
            keys = float(keys.strip()) / n
            rQ2_3[1][i] += keys
            l = f.readline()
            reg = l.split(":")[-1]
            reg = float(reg.strip()) / n
            rQ2_3[2][i] += reg
            l = f.readline()
        print(l)
        for i in range(nExp):
            time = l.split(":")[-1]
            time = float(time.strip()) / n
            rQ2_5[0][i] += time
            l = f.readline()
            keys = l.split(":")[-1]
            keys = float(keys.strip()) / n
            rQ2_5[1][i] += keys
            l = f.readline()
            reg = l.split(":")[-1]
            reg = float(reg.strip()) / n
            rQ2_5[2][i] += reg
            l = f.readline()
        print(l)
        for i in range(nExp):
            time = l.split(":")[-1]
            time = float(time.strip()) / n
            rQ2_7[0][i] += time
            l = f.readline()
            keys = l.split(":")[-1]
            keys = float(keys.strip()) / n
            rQ2_7[1][i] += keys
            l = f.readline()
            reg = l.split(":")[-1]
            reg = float(reg.strip()) / n
            rQ2_7[2][i] += reg
            l = f.readline()    
        print(l)
        for i in range(nExp):
            time = l.split(":")[-1]
            time = float(time.strip()) / n
            rQ3_10[0][i] += time
            l = f.readline()
            keys = l.split(":")[-1]
            keys = float(keys.strip()) / n
            rQ3_10[1][i] += keys
            l = f.readline()
            reg = l.split(":")[-1]
            reg = float(reg.strip()) / n
            rQ3_10[2][i] += reg
            l = f.readline()
        print(l)
        for i in range(nExp):
            time = l.split(":")[-1]
            time = float(time.strip()) / n
            rQ3_100[0][i] += time
            l = f.readline()
            keys = l.split(":")[-1]
            keys = float(keys.strip()) / n
            rQ3_100[1][i] += keys
            l = f.readline()
            reg = l.split(":")[-1]
            reg = float(reg.strip()) / n
            rQ3_100[2][i] += reg
            l = f.readline()
        print(l)
        for i in range(nExp):
            time = l.split(":")[-1]
            time = float(time.strip()) / n
            rQ4[0][i] += time
            l = f.readline()
            keys = l.split(":")[-1]
            keys = float(keys.strip()) / n
            rQ4[1][i] += keys
            l = f.readline()
            reg = l.split(":")[-1]
            reg = float(reg.strip()) / n
            rQ4[2][i] += reg
            l = f.readline()
        print(l)
        for i in range(nExp):
            time = l.split(":")[-1]
            time = float(time.strip()) / n
            rQ5[0][i] += time
            l = f.readline()
            keys = l.split(":")[-1]
            keys = float(keys.strip()) / n
            rQ5[1][i] += keys
            l = f.readline()
            reg = l.split(":")[-1]
            reg = float(reg.strip()) / n
            rQ5[2][i] += reg
            l = f.readline()
        print(l)
        for i in range(nExp):
            time = l.split(":")[-1]
            time = float(time.strip()) / n
            rheap[0][i] += time
            l = f.readline()
            keys = l.split(":")[-1]
            keys = float(keys.strip()) / n
            rheap[1][i] += keys
            l = f.readline()
            reg = l.split(":")[-1]
            reg = float(reg.strip()) / n
            rheap[2][i] += reg
            l = f.readline()

            time = l.split(":")[-1]
            time = float(time.strip()) / n
            rmerge[0][i] += time
            l = f.readline()
            keys = l.split(":")[-1]
            keys = float(keys.strip()) / n
            rmerge[1][i] += keys
            l = f.readline()
            reg = l.split(":")[-1]
            reg = float(reg.strip()) / n
            rmerge[2][i] += reg
            l = f.readline()
        if(l != ""):
            print("Error\n")
    
    wr = open("medias.txt", "w")

    wr.write("rQ1 N max = %fs\n"%(rQ1[0][6]))
    wr.write("rQ1 N max = %d keys cmp\n"%(rQ1[1][6]))
    wr.write("rQ1 N max = %d regs cpy\n"%(rQ1[2][6]))

    wr.write("rQ2 k = 3 N max = %fs\n"%(rQ2_3[0][6]))
    wr.write("rQ2 k = 3 N max = %d keys cmp\n"%(rQ2_3[1][6]))
    wr.write("rQ2 k = 3 N max = %d regs cpy\n"%(rQ2_3[2][6]))

    wr.write("rQ2 k = 5 N max = %fs\n"%(rQ2_5[0][6]))
    wr.write("rQ2 k = 5 N max = %d keys cmp\n"%(rQ2_5[1][6]))
    wr.write("rQ2 k = 5 N max = %d regs cpy\n"%(rQ2_5[2][6]))

    wr.write("rQ2 k = 7 N max = %fs\n"%(rQ2_7[0][6]))
    wr.write("rQ2 k = 7 N max = %d keys cmp\n"%(rQ2_7[1][6]))
    wr.write("rQ2 k = 7 N max = %d regs cpy\n"%(rQ2_7[2][6]))

    wr.write("rQ3 m = 10 N max = %fs\n"%(rQ3_10[0][6]))
    wr.write("rQ3 m = 10 N max = %d keys cmp\n"%(rQ3_10[1][6]))
    wr.write("rQ3 m = 10 N max = %d regs cpy\n"%(rQ3_10[2][6]))

    wr.write("rQ3 m = 100 N max = %fs\n"%(rQ3_100[0][6]))
    wr.write("rQ3 m = 100 N max = %d keys cmp\n"%(rQ3_100[1][6]))
    wr.write("rQ3 m = 100 N max = %d regs cpy\n"%(rQ3_100[2][6]))

    wr.write("rQ4 N max = %fs\n"%(rQ4[0][6]))
    wr.write("rQ4 N max = %d keys cmp\n"%(rQ4[1][6]))
    wr.write("rQ4 N max = %d regs cpy\n"%(rQ4[2][6]))

    wr.write("rQ5 N max = %fs\n"%(rQ5[0][6]))
    wr.write("rQ5 N max = %d keys cmp\n"%(rQ5[1][6]))
    wr.write("rQ5 N max = %d regs cpy\n"%(rQ5[2][6]))

    wr.write("rheap N max = %fs\n"%(rheap[0][6]))
    wr.write("rheap N max = %d keys cmp\n"%(rheap[1][6]))
    wr.write("rheap N max = %d regs cpy\n"%(rheap[2][6]))

    wr.write("rmerge N max = %fs\n"%(rmerge[0][6]))
    wr.write("rmerge N max = %d keys cmp\n"%(rmerge[1][6]))
    wr.write("rmerge N max = %d regs cpy\n"%(rmerge[2][6]))

    #genGraphics([rQ3_10, rheap, rmerge], ["QS seleção", "HeapSort", "MergeSort"], "resto")