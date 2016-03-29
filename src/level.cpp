#include "level.h"

Level::Level(){
    machine_opp.clear();//Enemies
    machine_p.clear();//Friendlies
    Objects_elite.clear();//Boss, etc
    //Objects_group.clear();
    Items.clear();//Items(e.g.dropped after killing enemy)
    Bullet.clear();
    Bullet_p.clear();
}

Level::~Level(){

}

void Level::move_objects(){
    move_machine();
    move_Objects_e();
    move_items();
    move_bullets();
}

//It seems at this point no multi-thread operation is required

void Level::move_machine(){
    move_machine_opp();
    move_machine_p();
}

void Level::move_bullets(){
    move_bullets_e();
    move_bullets_p();
}

void Level::move_machine_opp(){
    for (int i = 0; i < machine_opp.size(); ++i)
        machine_opp[i]->move();
}

void Level::move_machine_p(){
    for (int i = 0; i < machine_p.size(); ++i)
        machine_p[i]->move();
}

void Level::move_Objects_e(){
    for (int i = 0; i < Objects_elite.size(); ++i)
        Objects_elite[i]->move();
}

void Level::move_items(){
    for (int i = 0; i < Items.size(); ++i)
        Items[i]->move();
}

void Level::move_bullets_e(){
    for (int i = 0; i < Bullet.size(); ++i)
        Bullet[i]->move();
}

void Level::move_bullets_p(){
    for (int i = 0; i < Bullet_p.size(); ++i)
        Bullet_p[i]->move();
}

void Level::set_screen_ptr(sf::RenderTexture* src){
    _screen = src;
}

void Level::set_screen_ptr_objs(sf::RenderTexture* src){
    for (int i = 0; i < machine_opp.size(); ++i)
        machine_opp[i]->set_screen_ptr(src);//Enemies

    for (int i = 0; i < machine_p.size(); ++i)
        machine_p[i]->set_screen_ptr(src);//Friendlies

    for (int i = 0; i < Objects_elite.size(); ++i)
        Objects_elite[i]->set_screen_ptr(src);//Boss, etc

        //std::vector<Group*>         Objects_group;

    for (int i = 0; i < Items.size(); ++i)
        Items[i]->set_screen_ptr(src);//Items(e.g.dropped after killing enemy)

    for (int i = 0; i < Bullet.size(); ++i)
        Bullet[i]->set_screen_ptr(src);

    for (int i = 0; i < Bullet_p.size(); ++i)
        Bullet_p[i]->set_screen_ptr(src);
}

void Level::set_screen_ptr_all(sf::RenderTexture* src){
    set_screen_ptr(src);
    _world.set_screen_ptr(src);
    set_screen_ptr_objs(src);
}

void Level::render_objects(){
    for (int i = 0; i < machine_p.size(); ++i)
        machine_p[i]->render();//Friendlies
}

void Level::render_world(){
    _world.render_world();
}

void Level::set_camera_ptr(Camera* src){
    _camera = src;
}

void Level::set_camera_ptr_objs(Camera* src){
    for (int i = 0; i < machine_opp.size(); ++i)
        machine_opp[i]->set_camera_ptr(src);//Enemies

    for (int i = 0; i < machine_p.size(); ++i)
        machine_p[i]->set_camera_ptr(src);//Friendlies

    for (int i = 0; i < Objects_elite.size(); ++i)
        Objects_elite[i]->set_camera_ptr(src);//Boss, etc

        //std::vector<Group*>         Objects_group;

    for (int i = 0; i < Items.size(); ++i)
        Items[i]->set_camera_ptr(src);//Items(e.g.dropped after killing enemy)

    for (int i = 0; i < Bullet.size(); ++i)
        Bullet[i]->set_camera_ptr(src);

    for (int i = 0; i < Bullet_p.size(); ++i)
        Bullet_p[i]->set_camera_ptr(src);
}

void Level::set_camera_ptr_all(Camera* src){
    set_camera_ptr(src);
    _world.set_camera_ptr(src);
    set_camera_ptr_objs(src);
}

void Level::change_player_dir(Engine::Key_type key){
    //vector3d*->change_dir()
    ( machine_p[Engine::player_idx]->get_velocity() )->change_dir(key);
}

void Level::update_world_pos(){
    Vector3d* vel = machine_p[Engine::player_idx]->get_velocity();
    _world.update_bg_pos_all(*vel);
}
