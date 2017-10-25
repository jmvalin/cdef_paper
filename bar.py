#!/usr/bin/python

import numpy as np
import matplotlib.pyplot as plt


n_groups = 6

cdef = (4, 10.001, 9, 9, 6, 5)
tie = (4, 1, 2, 2, 5, 4)
none = (4, 1, 1, 1, 1, 3)

fig, ax = plt.subplots(figsize=(8, 4))

index = np.arange(n_groups)-.625
bar_width = 0.25

opacity = 0.4
error_config = {'ecolor': '0.3'}

rects1 = plt.bar(index-bar_width, cdef, bar_width,
                 color='#000070',
                 label='Prefer CDEF')

rect_tie = plt.bar(index, tie, bar_width,
                 color='#70D050',
                 label='No preference')

rects2 = plt.bar(index + bar_width, none, bar_width,
                 color='#C02020',
                 label='Prefer No CDEF')

clips = ('MINECRAFT', 'Crosswalk', 'DinnerScene', 'TunnelFlag', 'sintel', 'vidyo1')
#plt.xlabel('Sequence')
#plt.ylabel('Score')
#plt.title('Scores by group and gender')
plt.xticks(index + bar_width / 2, clips)
plt.legend()
#plt.grid(True)
plt.gca().yaxis.grid(True)

plt.tight_layout()
#plt.show()
plt.savefig("cdef_vs_nothing.pdf", bbox_inches='tight')
