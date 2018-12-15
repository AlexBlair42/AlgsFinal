# Referenced https://www.saltycrane.com/blog/2008/01/how-to-find-intersection-and-union-of/ for unions.
# Referenced https://www.geeksforgeeks.org/detect-cycle-in-a-graph/ for checking if acyclic.

# File Input
file = open("matrix2.txt")
graph = [[int(val) for val in line.split()] for line in file]
vertices = []
cost = 0


# Filling vertices
for r in range(0, len(graph)):
	vertices.append(r)

	
# Set up a list to manage visited nodes.
visit = [False] * len(vertices)
r = [False] * len(vertices)


#Checking to see if there are any cycles in the minimum spanning tree.
def isAcyclic(x):
	for num in range(0,len(graph)):
		if visit[num] == True and visit[num+1] == False:
			visit[num+1] = True
			return False
		elif visit[num] == True and visit[num+1] == True:
			return True
	return False

	
# Get the union of "Answer" and "list of edges from "graph".
def union(uA, uE):
	return list(set(uA) | set(uE))

	
# Selects edges based on their weight and traverses the graph making a minimum spanning tree.
def kruskal():
	answer = []
	encounter = 0
	k = 0
	visit[0] = True
	while encounter < (len(vertices)-1):
		holder = union(answer, graph[k])
		if isAcyclic(holder):
			answer = union(answer,graph[k])
			encounter += 1
		k+= 1
	return answer

	
# Set output to the minimum spanning tree.
output = kruskal()


# Add up the cost of the spanning tree.
for x in range(0, len(output)):
	cost += output[x]


# Display the minimum spanning tree and the total cost.
#print(output)
print(cost)
print(output)