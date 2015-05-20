<?php

function addressbook_delete($contact_id) {
  db_delete('adressbook_table')
    ->condition('addressbook_id', arg(3))
    ->execute();
  drupal_goto('admin/content/contacts');
}