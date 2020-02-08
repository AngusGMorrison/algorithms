package dijkstra;

import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Objects;
import java.util.Set;

public class Graph {
	private Set<Node> nodes;
	
	public Graph(Node... nodes) {
		this.nodes = new HashSet<>(Arrays.asList(nodes));
	}
	
	public Set<Node> getNodes() {
		return nodes;
	}
	
	public void addNodes(Node... nodes) {
		this.nodes.addAll(Arrays.asList(nodes));
	}
	
	public void addEdge(Node source, Node destination, int weight) {
		if (!(nodes.contains(source) && nodes.contains(destination))) {
			throw new IllegalArgumentException("Node is not in graph");
		}	
		if (hasEdge(source, destination)) {
			throw new IllegalArgumentException("Nodes already have an edge");
		}
		addNodes(source, destination);
		source.getEdges().add(new Edge(source, destination, weight));
	}
	
	public boolean hasEdge(Node source, Node destination) {
		List<Edge> edges = source.getEdges();
		for (Edge edge : edges) {
			if (Objects.equals(edge.getDestination(), destination)) {
				return true;
			}
		}
		return false;
	}
	
	public void printEdges() {
		for (Node node : nodes) {
			List<Edge> edges = node.getEdges();
			
			if (edges.isEmpty()) {
				System.out.println("Node " + node.getName() + " has no edges");
				continue;
			}
			
			System.out.println("Node " + node.getName() + " has edges to: ");
			for (Edge edge : edges) {
				System.out.print(edge.getDestination().getName() + "(" + edge.getWeight() + ") ");
			}
			System.out.println();
			
		}
	}
	
	public void resetNodesVisited() {
		nodes.forEach(node -> node.unvisit());
	}
	
	
}
