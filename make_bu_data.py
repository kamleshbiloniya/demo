from __future__ import absolute_import
from __future__ import division
from __future__ import print_function

import os
import base64
import numpy as np
import csv
import sys
import zlib
import time
import mmap
import argparse

parser = argparse.ArgumentParser()

# output_dir
parser.add_argument('--downloaded_feats', default='data/bu_data', help='downloaded feature directory')
parser.add_argument('--output_dir', default='data/cocobu', help='output feature files')

args = parser.parse_args()

csv.field_size_limit(sys.maxsize)


FIELDNAMES = ['image_id', 'image_w','image_h','num_boxes', 'boxes', 'features']
infiles = ['trainval/karpathy_test_resnet101_faster_rcnn_genome.tsv',
           'trainval/karpathy_val_resnet101_faster_rcnn_genome.tsv',\
           'trainval/karpathy_train_resnet101_faster_rcnn_genome.tsv.0', \
            'trainval/karpathy_train_resnet101_faster_rcnn_genome.tsv.1']

#for 36 version
#infiles = ['trainval_36/trainval_resnet101_faster_rcnn_genome_36.tsv']

# os.makedirs(args.output_dir+'_att')
# os.makedirs(args.output_dir+'_fc')
# os.makedirs(args.output_dir+'_box')
cocobu_size = {}
###################kamlesh###########
data = []
f = open("data/files.txt","r")
for i in range(94430):
    line = f.readline()
    # lst = line.split(' ')
    data.append([line])
# print(data)

############### kamlesh##########

for infile in infiles:
    print('Reading ' + infile)
    with open(os.path.join(args.downloaded_feats, infile), "r+b") as tsv_in_file:
        reader = csv.DictReader(tsv_in_file, delimiter='\t', fieldnames = FIELDNAMES)
        for item in reader:
            item['image_id'] = int(item['image_id'])
            item['num_boxes'] = int(item['num_boxes'])
            item['image_w'] = int(item['image_w'])
            item['image_h'] = int(item['image_h'])
            ##########kamlesh##########
            myid = item['image_id']
            if([str(myid)+'.npy\n'] in data):
                print("continue--",myid)
                continue
            ##############kamlesh#######
            for field in ['boxes', 'features']:
                item[field] = np.frombuffer(base64.decodestring(item[field]),
                        dtype=np.float32).reshape((item['num_boxes'],-1))
            np.savez_compressed(os.path.join(args.output_dir+'_att', str(item['image_id'])), feat=item['features'])
            np.save(os.path.join(args.output_dir+'_fc', str(item['image_id'])), item['features'].mean(0))
            np.save(os.path.join(args.output_dir+'_box', str(item['image_id'])), item['boxes'])
            cocobu_size_temp = {}
            cocobu_size_temp['image_w'] = item['image_w']
            cocobu_size_temp['image_h'] = item['image_h']
            cocobu_size[str(item['image_id'])] = cocobu_size_temp
save_path = '/home/yangxu/project/self-critical.pytorch/data/cocobu_size.npz'
np.savez(save_path, roidb=cocobu_size)




