#! /usr/bin/python3

import os
from re import sub

import matplotlib.pyplot as plot

def load_data(file):
    raw_data = None
    try:
        with open(file) as fp:
            raw_data = [float(sub(',', '', i)) for i in fp.read().split('\n')[:-1]]
    except FileNotFoundError:
        print('%s does not exist' % file)
    return raw_data

pwd = os.getcwd()

durations = []
peaks = []

for plugin in os.listdir('data'):
    for pluglet in os.listdir('data/%s' % plugin):
        print('%s/%s' % (plugin, pluglet))
        os.chdir('data/%s/%s' % (plugin, pluglet))
        data = os.listdir()

        raw_durations = load_data('durations.txt')
        raw_peaks = load_data('peaks.txt')

        print(raw_durations)
        durations.append(raw_durations)

        print(raw_peaks)
        peaks.append(raw_peaks)
        
        os.chdir(pwd)

fontsize = 24
fig, (ax1, ax2) = plot.subplots(2, 1)
ax1.boxplot(durations)
ax1.set_ylabel('Total duration [s]', fontsize=fontsize)
ax1.tick_params(labelsize=fontsize - 4)

#ax2.plot(range(1, len(peaks)+1), [i[0]/1000000 for i in peaks], 'bo')
ax2.bar(range(1, len(peaks)+1), [i[0]/1000000 for i in peaks])
ax2.tick_params(labelsize=fontsize - 4)
ax2.set_ylabel('Total memory usage [MB]', fontsize=fontsize)
ax2.set_xlabel('Pluglets', fontsize=fontsize)

plot.xticks(range(1, len(peaks)+1))
plot.show()

"""
plot.boxplot(durations)
plot.ylabel('Total duration [s]')
plot.xlabel('Pluglets')
plot.show()

plot.plot([1, 2, 3, 4], [i[0]/1000000 for i in peaks], 'bo')
plot.ylabel('Maximum memory usage [MB]')
plot.xlabel('Pluglets')
plot.show()
"""

