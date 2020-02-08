package priorityQueueDijkstra;

import java.util.HashSet;
import java.util.Map.Entry;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Set;

public class Dijkstra {
	private Set<Node> settledNodes;
	private Queue<Node> unsettledNodes;
	
	public void pathfind(Node source) {	
		initialize(source);
		
		while (!unsettledNodes.isEmpty()) {
			Node currentNode = unsettledNodes.remove();		
			for (Entry<Node, Integer> pair : currentNode.getAdjacentNodes().entrySet()) {
				Node adjacentNode = pair.getKey();
				Integer weight = pair.getValue();
				if (!settledNodes.contains(adjacentNode)) {
					calculateShortestPath(adjacentNode, weight, currentNode);
					unsettledNodes.add(adjacentNode);
				}
			}
			settledNodes.add(currentNode);
		}
	}
	
	private void initialize(Node source) {
		settledNodes = new HashSet<>();
		unsettledNodes = new PriorityQueue<>();
		source.setMinDistance(0);
		unsettledNodes.add(source);
	}
	
	private void calculateShortestPath(Node evaluationNode, int weight, Node referenceNode) {
		int pathLength = referenceNode.getMinDistance() + weight;
		if (evaluationNode.getMinDistance() > pathLength) {
			evaluationNode.setMinDistance(pathLength);
			evaluationNode.updatePredecessors(referenceNode);
		}
	}
	
}
