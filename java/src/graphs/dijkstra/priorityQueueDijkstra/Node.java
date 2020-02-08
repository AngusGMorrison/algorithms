package priorityQueueDijkstra;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

public class Node implements Comparable<Node> {
	private final String id;
	private Map<Node, Integer> adjacentNodes = new HashMap<>();
	private Integer minDistance = Integer.MAX_VALUE;
	private List<Node> predecessors = new LinkedList<>();
	
	public Node(String id) {
		this.id = id;
	}
	
	public String getId() {
		return id;
	}
	
	public Map<Node, Integer> getAdjacentNodes() {
		return adjacentNodes;
	}
	
	public void addAdjacent(Node node, Integer weight) {
		adjacentNodes.put(node, weight);
	}
	
	public Integer getMinDistance() {
		return minDistance;
	}
	
	public void setMinDistance(Integer distance) {
		minDistance = distance;
	}
	
	public List<Node> getPredecessors() {
		return predecessors;
	}
	
	public void updatePredecessors(Node previousNode) {
		List<Node> newPredecessors = new LinkedList<>(previousNode.getPredecessors());
		newPredecessors.add(previousNode);
		this.predecessors = newPredecessors;
	}
	
	public void reset() {
		minDistance = Integer.MAX_VALUE;
		predecessors = new LinkedList<>();
	}
	
	@Override
	public String toString() {
		return id;
	}
	
	public int compareTo(Node other) {
		return minDistance - other.minDistance;
	}
	
}
