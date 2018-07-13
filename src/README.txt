##################################################################### 
Algoritmos
#####################################################################

- Para compilar:

    $ make

- Para executar:

    $ ./main [opt1] [opt2] [opt3] "[...].txt"
    
    Onde
        opt1 (obrigatório):
            (1): Algoritmo de Kruskal
            (2): Algoritmo de Prim
            
        opt2 (obrigatório):
            Valor inteiro com o número de clusters
            
        opt3 (opcional):
            "-t": modo de exibição do tempo de execução de
                  cada algoritmo
                  
        "[...].txt" (obrigatório):
            nome e local do arquivo de texto com as classificações,
            necessariamente nos formatos:
            
            - Kruskal: ../output/kruskal_classes.txt
            - Prim: ../output/prim_classes.txt 
            
- Exemplo

    $ ./main 1 7 -t ../output/kruskal_classes.txt
    
##################################################################### 
Script visualization.py
#####################################################################

- Módulos necessários:

    - numpy
    - matplotlib
    - scipy
    - scikit-learn
    
- Para executar:

    $ python3 visualization.py [opt1] [opt2]
    
    Onde
        
        opt1 (obrigatório):
            k: Algoritmo de Kruskal
            p: Algoritmo de Prim
            
        opt2 (obrigatório):
            1: Rand Index
            2: Adjusted Rand Index
        
