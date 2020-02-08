package inefficientDijkstra;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Objects;
import java.util.Set;

public class Dijkstra {
	private final List<Vertex> nodes;
	private final List<Edge> edges;
	private Set<Vertex> settledNodes;
	// Can't use PriorityQueue with this implementation
	// No means of comparing vertices
	private Set<Vertex> unsettledNodes;
	private Map<Vertex, Vertex> predecessors;
	private Map<Vertex, Integer> distances;
	
	public Dijkstra(Graph graph) {
		this.nodes = new ArrayList<>(graph.getVertices());
		this.edges = new ArrayList<>(graph.getEdges());
	}
	
	public void pathfind(Vertex source) {
		initialize(source);
		
		while (unsettledNodes.size() > 0) {
			Vertex node = getMinDistanceNode();
			findMinNeighborDistances(node);
			settledNodes.add(node);
			unsettledNodes.remove(node);
		}
	
	}
	
	private void initialize(Vertex source) {
		settledNodes = new HashSet<>();
		unsettledNodes = new HashSet<>();
		predecessors = new HashMap<>();
		distances = new HashMap<>();
		
		distances.put(source, 0);
		unsettledNodes.add(source);
	}
	
	private Vertex getMinDistanceNode() {
		Vertex minDistanceNode = null;
		for (Vertex node : unsettledNodes) {
			if (minDistanceNode == null) {
				minDistanceNode = node;
			} else if (getDistanceFromSource(node) < getDistanceFromSource(minDistanceNode)){
				minDistanceNode = node;
			}
		}
		return minDistanceNode;
	}
	
	private void findMinNeighborDistances(Vertex node) {
		List<Vertex> neighbors = getNeighbors(node);
		for (Vertex neighbor : neighbors) {
			if (pathIsShorter(node, neighbor)) {
				distances.put(neighbor, getDistanceFromSource(node) + getDistanceBetween(node, neighbor));
				predecessors.put(neighbor, node);
				unsettledNodes.add(neighbor);
			}
		}
	}
	
	private List<Vertex> getNeighbors(Vertex node) {
		// This is massively inefficient. A node should know about its neighbors/edges to prevent this iteration.
		List<Vertex> neighbors = new ArrayList<>();
		for (Edge edge : edges) {
			if (Objects.equals(edge.getSource(), node) && !isSettled(edge.getDestination())) {
				neighbors.add(edge.getDestination());
			}
		}
		return neighbors;
	}
	
	private boolean isSettled(Vertex node) {
		return settledNodes.contains(node);
	}
	
	private boolean pathIsShorter(Vertex node, Vertex neighbor) {
		return getDistanceFromSource(node) + getDistanceBetween(node, neighbor) < getDistanceFromSource(neighbor);
	}
	
	private int getDistanceFromSource(Vertex destination) {
		return distances.getOrDefault(destination, Integer.MAX_VALUE);
	}
	
	private Integer getDistanceBetween(Vertex node, Vertex neighbor) {
		// Horrible iteration
		Integer distance = null;
		for (Edge edge : edges) {
			if (Objects.equals(edge.getSource(), node) &&
				Objects.equals(edge.getDestination(), neighbor)) {
				distance = edge.getWeight();
			}
		}
		return distance;
	}
}

