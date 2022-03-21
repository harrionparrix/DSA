graph={
    'a': {'a' : 0,  'b': 7,     'c': 2,     'd': 100,     'e': 100},
    'b': {'a' :7,   'b' :0,     'c' :6,     'd' :100,    'e' :5},
    'c': {'a' :2,    'b' :6,    'c' :0,      'd' :4,     'e' :100},
    'c': { 'a' :2,   'b' :6,    'c' :0,      'd' :4,     'e' :100},
    'd': {'a' :100,   'b' :100,   'c' :4,     'd' :0,     'e' :2},
    'e': {'a' :100,    'b' :5,     'c' :100,   'd' :2,    'e' :0}
}

path={}
visited ={}

def printpath():
    for i in path:
        print(i,path[i])    

def initialize(source): 
    for i in graph.keys():
        path[i]=[' ',100]
        visited[i]=False

        path[source][1]=0
        visited[source]=True          

def mindist():
    min=100
    mind=dict(sorted(path.items(), key=lambda item: item[1]))
    for x,v in mind.items():
        if visited[x]==False:
            return x 
         

def djkstra(source, destination):         
    while not visited[destination]:
        
        min_dist=mindist()
        visited[min_dist]=True

        for vertex in list(path.keys()):
            if (visited[vertex] and vertex!=min_dist):
             
                if(path[min_dist][1]==100 and graph[min_dist][vertex]<path[vertex][1]):
                    path[min_dist][1]=graph[min_dist][vertex]+path[vertex][1]
                    path[min_dist][0]=vertex
                  
                elif(path[vertex][1]+graph[min_dist][vertex]<path[min_dist][1]):
                    path[min_dist][1]=path[vertex][1]+graph[min_dist][vertex]
                    path[min_dist][0]=vertex    
                                

def shortest(path,source,destination):
    l=[]
    vertex=destination
    l.append(vertex)

    while(path[vertex][0]!=source):
        vertex=path[vertex][0]
        l.append(vertex)
    
    l.append(source)
    l.reverse()
    print(*l,sep="->")


if __name__ == "__main__":
    source=input("Enter Source  ")
    destination=input("Enter Destination  ")
    initialize(source)

    djkstra(source,destination) 
    printpath()
    shortest(path,source,destination)