"use strict";

function devide(parent, nodeinfo, tree, dir) {

  if(nodeinfo.length === 0) return;

  // 루트 구하기
  let root;
  let max_idx = 0;
  let max_y = nodeinfo[max_idx][1];
  for(let i = 0; i < nodeinfo.length; i++) {
    if(max_y < nodeinfo[i][1]) {      
      max_y = nodeinfo[i][1];
      max_idx = i;
    }
  }
  root = nodeinfo[max_idx];  
  if(!tree.hasOwnProperty(parent)) {
    tree[parent] = {};
  }
  tree[parent][dir] = root;  

  // left, right 구하기
  let left = [];
  let right = [];
  for(let i = 0; i < nodeinfo.length; i++) {
    if(nodeinfo[i][0] < root[0]) {
      left.push(nodeinfo[i]);      
    } else if(nodeinfo[i][0] > root[0]) {
      right.push(nodeinfo[i]);
    }
  }
  devide(root[2], left, tree, 'left');
  devide(root[2], right, tree, 'right');
}

function preOrder(root, tree, arr) {
  arr.push(root);  
  tree[root] !== undefined && tree[root]['left'] !== undefined && preOrder(tree[root]['left'][2], tree, arr);
  tree[root] !== undefined && tree[root]['right'] !== undefined && preOrder(tree[root]['right'][2], tree, arr);
}

function postOrder(root, tree, arr) {
  tree[root] !== undefined && tree[root]['left'] !== undefined && postOrder(tree[root]['left'][2], tree, arr);
  tree[root] !== undefined && tree[root]['right'] !== undefined && postOrder(tree[root]['right'][2], tree, arr);  
  arr.push(root);    
}


function solution(nodeinfo) {
  var answer = [];

  nodeinfo.forEach((e, i) => {
    e.push(i+1);
  });
  let tree = {};
  devide(0, nodeinfo, tree, 'root');
  // console.log(tree);

  let pre_arr = [];
  let post_arr = [];  
  preOrder(tree[0]['root'][2], tree, pre_arr);
  postOrder(tree[0]['root'][2], tree, post_arr);
  answer.push(pre_arr);
  answer.push(post_arr);
  // console.log(answer);

  return answer;
}

let nodeinfo = [[5,3],[11,5],[13,3],[3,5],[6,1],[1,3],[8,6],[7,2],[2,2]];
solution(nodeinfo);