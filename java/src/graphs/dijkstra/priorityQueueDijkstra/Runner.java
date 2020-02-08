package priorityQueueDijkstra;

public class Runner {
	public static void main(String[] args) {
		Node nodeA = new Node("A");
		Node nodeB = new Node("B");
		Node nodeC = new Node("C");
		Node nodeD = new Node("D");
		Node nodeE = new Node("E");
		Node nodeF = new Node("F");
		
		nodeA.addAdjacent(nodeB, 10);
		nodeB.addAdjacent(nodeA, 10);
		nodeA.addAdjacent(nodeC, 15);
		nodeC.addAdjacent(nodeA, 15);
		
		nodeB.addAdjacent(nodeD, 12);
		nodeD.addAdjacent(nodeB, 12);
		nodeB.addAdjacent(nodeF, 15);
		nodeF.addAdjacent(nodeB, 15);
		
		nodeC.addAdjacent(nodeE, 10);
		nodeE.addAdjacent(nodeC, 10);
		
		nodeD.addAdjacent(nodeE, 2);
		nodeE.addAdjacent(nodeD, 2);
		nodeD.addAdjacent(nodeF, 1);
		nodeF.addAdjacent(nodeD, 1);
		
		nodeF.addAdjacent(nodeE, 5);
		nodeE.addAdjacent(nodeF, 5);
		
		Graph graph = new Graph(nodeA, nodeB, nodeC, nodeD, nodeE, nodeF);
		Dijkstra dijkstra = new Dijkstra();
		
		dijkstra.pathfind(nodeA);
		System.out.println(nodeE.getPredecessors().toString());
		System.out.println(nodeF.getPredecessors().toString());
		
		graph.resetNodes();
		dijkstra.pathfind(nodeF);
		System.out.println(nodeA.getPredecessors().toString());
		System.out.println(nodeC.getPredecessors().toString());
	}
}
