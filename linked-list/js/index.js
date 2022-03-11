class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

class LinkedList {
  constructor() {
    this.head = null;
    this.size = 0;
  }

  add(data) {
    let newNode = new Node(data);
    if (this.head === null) {
      this.head = newNode;
    } else {
      let current = this.head;
      while (current.next) {
        current = current.next;
      }
      current.next = newNode;
    }
    this.size += 1;
  }

  addAt(index, data) {
    if (index > this.size || index < 0) {
      console.log("Please enter a valid index!");
      return;
    } else {
      let newNode = new Node(data);
      if (index === 0) {
        newNode.next = this.head;
        this.head = newNode;
      } else {
        let current = this.head;
        for (let i = 0; i < index - 1; i++) {
          current = current.next;
        }
        newNode.next = current.next;
        current.next = newNode;
      }
      this.size += 1;
    }
  }

  deleteNode(index) {
    if (index > this.size || index < 0) {
      console.log("Please enter a valid index!");
    } else {
      let current = this.head;
      if (index == 0) {
        this.head = current.next;
        return;
      }
      for (let i = 0; i < index - 1; i++) {
        current = current.next;
      }
      let copy = current.next;
      current.next = copy.next;
      this.size -= 1;
    }
  }

  reverse() {
    let current = this.head;
    let previous = null;
    let next;
    while (current) {
      next = current.next;
      current.next = previous;
      previous = current;
      current = next;
    }
    this.head = previous;
  }

  print() {
    let current = this.head;
    while (current) {
      console.log(current.data);
      current = current.next;
    }
  }
}
