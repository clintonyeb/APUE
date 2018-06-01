const inits = [
    {id: 1, name: "test", tagId: 1},
    {id: 2, name: "test", tagId: 15},
    {id: 3, name: "test", tagId: 5},
];

const ids = inits.map(init => init.tagId);

const results = [
    {id: 1, name: "tag1"},
    {id: 15, name: "tag2"},
    {id: 5, name: "tag3"},
];

const final = inits.map(init => {
    init.tag = results.find(res => res.id === init.tagId)
    return init;
});
