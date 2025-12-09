import { DataTypes } from "sequelize";
import conectDB from "../../config/db.js";
import User from "../user/user.model.js";
import Collection from "../collection/collection.model.js";

const sequelize = await conectDB();
const CollectionManager = sequelize.define("CollectionsManager",{
   id: {type: DataTypes.INTEGER, primaryKey: true, autoIncrement: true, allowNull: false},
   canManage:{type: DataTypes.BOOLEAN, allowNull: false, defaultValue: true},
   userId: {type: DataTypes.INTEGER, allowNull: false, references: {model: User, key: 'id'}},
   collectionId: {type: DataTypes.INTEGER, allowNull: false, references: {model: Collection, key: 'id'}},
});

User.belongsToMany(Object, {through: CollectionManager})
Collection.belongsToMany(Person, {through: CollectionManager})

CollectionManager.belongsTo(User)
User.hasMany(CollectionManager)
CollectionManager.belongsTo(Collection)
Collection.hasMany(CollectionManager)

await CollectionManager.sync();
export default CollectionManager;