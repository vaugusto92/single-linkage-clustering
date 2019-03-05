# Minimum Spanning Tree Single Linkage Clustering

Single linkage clustering approach by means of Minimum Spanning Tree Prim and Kruskal algorithms. 
# ############### Algorithms

#### To compile:

```sh
$ make
```

#### To run:

```sh
$ ./main [opt1] [opt2] [opt3] *.txt
```

- opt1 (mandatory):
-- Kruskal's MST Algorithm;
-- Prim's MST Algorithm;

- opt2 (mandatory):
-- integer number of clusters;
            
- opt3 (optional):
-- "-t": shows the running time of each algorithm;
                  
- "[...].txt" (mandatory):
-- path for the .txt file with labels, where:
--- Kruskal: ../output/kruskal_classes.txt
--- Prim: ../output/prim_classes.txt 

#### Example

```sh
$ ./main 1 7 -t ../output/kruskal_classes.txt
```

# ############### Visualization

#### Necessary modules:

- NumPy
- SciPy
- Matplotlib
- Scikit-learn

#### To run:

```sh
$ python3 visualization.py [opt1] [opt2]
```

- opt1 (mandatory):
-- k: Kruskal's MST Algorithm;
-- p: Prim's MST Algorithm;

- opt2 (mandatory):
-- 1: rand index;
-- 2: adjusted rand index.
