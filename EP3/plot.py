#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Nov 22 21:41:05 2020

@author: fernanda
"""

import numpy as np
import matplotlib.pyplot as plt

def main():
    data_des = np.loadtxt ('ep3_des.txt')
    data_ord = np.loadtxt ('ep3_ord.txt')
    data_pord = np.loadtxt ('ep3_pord.txt')
    
    #defining var.
    bs_des = data_des[data_des[:, 0] == 1] 
    is_des = data_des[data_des[:, 0] == 2]
    ms_des = data_des[data_des[:, 0] == 3]
    qs_des = data_des[data_des[:, 0] == 4]
    qsa_des = data_des[data_des[:, 0] == 5]
    hs_des = data_des[data_des[:, 0] == 6]
    
    bs_pord = data_pord[data_pord[:, 0] == 1] 
    is_pord = data_pord[data_pord[:, 0] == 2]
    ms_pord = data_pord[data_pord[:, 0] == 3]
    qs_pord = data_pord[data_pord[:, 0] == 4]
    qsa_pord = data_pord[data_pord[:, 0] == 5]
    hs_pord = data_pord[data_pord[:, 0] == 6]
    
    bs_ord = data_ord[data_ord[:, 0] == 1] 
    is_ord = data_ord[data_ord[:, 0] == 2]
    ms_ord = data_ord[data_ord[:, 0] == 3]
    qs_ord = data_ord[data_ord[:, 0] == 4]
    qsa_ord = data_ord[data_ord[:, 0] == 5]
    hs_ord = data_ord[data_ord[:, 0] == 6]
    
    
    #plotting
    fig_d, (ax1, ax2, ax3) = plt.subplots (1, 3)
    
    ax1.plot (bs_des[:,1], bs_des[:,2], label = "Bubblesort")
    ax1.plot (is_des[:,1], is_des[:,2], label = "Insertion sort")
    ax1.plot (ms_des[:,1], ms_des[:,2], label = "Mergesort")
    ax1.plot (qs_des[:,1], qs_des[:,2], label = "Quicksort")
    ax1.plot (qsa_des[:,1], qsa_des[:,2], label = "Quicksort Aleatório")
    ax1.plot (hs_des[:,1], hs_des[:,2], label = "Heapsort")
    
    ax1.legend (loc = 'upper left')
    ax1.set_title ("Aleatórios", fontsize = 13, fontweight = 'bold')
    ax1.set (xlabel = 'n', ylabel = 'Total de Comp./Mov./Trocas')
    
    ax2.plot (bs_pord[:,1], bs_pord[:,2], label = "Bubblesort")
    ax2.plot (is_pord[:,1], is_pord[:,2], label = "Insertion sort")
    ax2.plot (ms_pord[:,1], ms_pord[:,2], label = "Mergesort")
    ax2.plot (qs_pord[:,1], qs_pord[:,2], label = "Quicksort")
    ax2.plot (qsa_pord[:,1], qsa_pord[:,2], label = "Quicksort Aleatório")
    ax2.plot (hs_pord[:,1], hs_pord[:,2], label = "Heapsort")
    
    ax2.legend (loc = 'upper left')
    ax2.set_title ("Parcicalmente ordenados", fontsize = 13, fontweight = 'bold')
    ax2.set (xlabel = 'n', ylabel = 'Total de Comp./Mov./Trocas')
    
    ax3.plot (bs_ord[:,1], bs_ord[:,2], label = "Bubblesort")
    ax3.plot (is_ord[:,1], is_ord[:,2], label = "Insertion sort")
    ax3.plot (ms_ord[:,1], ms_ord[:,2], label = "Mergesort")
    ax3.plot (qs_ord[:,1], qs_ord[:,2], label = "Quicksort")
    ax3.plot (qsa_ord[:,1], qsa_ord[:,2], label = "Quicksort Aleatório")
    ax3.plot (hs_ord[:,1], hs_ord[:,2], label = "Heapsort")
    
    ax3.legend (loc = 'upper left')
    ax3.set_title ("Ordenados", fontsize = 13, fontweight = 'bold')
    ax3.set (xlabel = 'n', ylabel = 'Total de Comp./Mov./Trocas')

    plt.show()
    
if __name__ == '__main__':
    main()
