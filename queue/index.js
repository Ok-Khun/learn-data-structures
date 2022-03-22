class Queue {
  constructor() {
    this.collection = [];
  }
  enQueue(data) {
    return this.collection.push(data);
  }
  deQueue() {
    return this.collection.shift();
  }
  front() {
    return this.collection[0];
  }
  size() {
    return this.collection.length;
  }
  isEmpty() {
      return this.collection.length === 0;
  }
}

let q = new Queue();

q.enQueue(10);
q.enQueue(20);
q.enQueue(30);
q.enQueue(40);
q.deQueue();
console.log(q);

